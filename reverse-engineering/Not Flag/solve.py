import angr
import claripy
import sys

'''
$ docker run --rm -it -v (pwd):/home/angr/mnt angr/angr
(angr) angr@340d554138cc:~$ cd mnt/
(angr) angr@340d554138cc:~/mnt$ python solve.py notflag
...
b'CUCTF{17_c0uld_h4v3_b33n_4_h07d06}'
'''

def main(argv):
    project = angr.Project(argv[1], load_options={
        'auto_load_libs': False
    })

    # The binary is calling read(stdin, flag, sizeof(flag))
    flag = claripy.BVS('flag', 34*8)
    state = project.factory.entry_state(
        stdin=flag
    )

    simulation = project.factory.simgr(state, veritesting=True)

    def is_successful(state):
        stdout_output = state.posix.dumps(sys.stdout.fileno())
        return b'''Flag''' in stdout_output

    def should_abort(state):
        stdout_output = state.posix.dumps(sys.stdout.fileno())
        return b'''Not Flag''' in stdout_output

    simulation.explore(find=is_successful, avoid=should_abort)

    if simulation.found:
        solution_state = simulation.found[0]
        print(solution_state.solver.eval(flag, cast_to=bytes))
    else:
        raise Exception('Could not find the solution')

if __name__ == '__main__':
    main(sys.argv)
