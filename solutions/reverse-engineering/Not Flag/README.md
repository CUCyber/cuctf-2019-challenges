# Not Flag

This is an obvious angr problem. We have:

1. A success/fail case
2. An input
3. Constraints in `check()`

We could also solve this problem with a SAT solver like z3 but that would require us to parse the assembly into the constraints.

We'll start off by defining a project in angr.

```Python
project = angr.Project(argv[1], load_options={
    'auto_load_libs': False
})
```

The binary is calling `read(stdin, flag, sizeof(flag))`, so we'll define a bitvector using claripy to represent our flag. It's 34 bytes long and there are 8 bits in a byte.

```Python
flag = claripy.BVS('flag', 34*8)
```

We need to define an entry state but we also need to specify that stdin should contain our flag bitvector.

```Python
state = project.factory.entry_state(
    stdin=flag
)
```

Now we need to define a simulation manager. It's important here that we enable veritesting. Veritesting is an exploration technique made for condensing chunks of code to single (nested) if-then-else constraints. It essentially makes our exploration a lot faster (and anecdotally more accurate).

```Python
simulation = project.factory.simgr(state, veritesting=True)
```

Next, we need to define our success and failure cases. By taking a quick look at the binary's strings, we can determine that a successful flag entry results in the binary outputting "Flag" and an unsuccessful flag submission results in "Not flag".

```Python
def is_successful(state):
    stdout_output = state.posix.dumps(sys.stdout.fileno())
    return b'''Flag''' in stdout_output

def should_abort(state):
    stdout_output = state.posix.dumps(sys.stdout.fileno())
    return b'''Not flag''' in stdout_output
```

Finally, we'll explore the simulation and print our flag if it is found.

```Python
simulation.explore(find=is_successful, avoid=should_abort)

if simulation.found:
    solution_state = simulation.found[0]
    print(solution_state.solver.eval(flag, cast_to=bytes))
else:
    raise Exception('Could not find the solution')
```

```
CUCTF{17_c0uld_h4v3_b33n_4_h07d06}
```
