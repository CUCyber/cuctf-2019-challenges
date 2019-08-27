import random

flag = "CUCTF{17_c0uld_h4v3_b33n_4_h07d06}"

flatten = lambda _: [i for __ in _ for i in __]
flagmap = lambda _: ord(flag[_])

def generate_function(cs_pairs):
    fmt  = 'int check(){\n'
    fmt += '\tint checks = 0;\n'
    for pair in cs_pairs:
        constraint, flag_sum = pair
        fmt += ''.join([
            '\tif (',
            '+'.join([f'flag[{i}]' for i in constraint]),
            " == {0}) checks++;\n".format(flag_sum)
        ])
    return fmt + f'\n\treturn checks == {len(cs_pairs)};\n}}'

def generate_constraints(num_constraints, max_constraint_vars):
    if len(flag) <= 2:
        print("The flag is too short")
        quit()

    constraints = [{
        'vars': 0,
        'constraint': []
    } for i in range(0, num_constraints)]

    max_constraint_vars = min(max_constraint_vars, len(flag))
    for i in range(0, num_constraints):
        constraints[i]['vars'] = random.randint(2, max_constraint_vars)

    for eq in constraints:
        for i in range(eq['vars']):
            rand = random.randint(0, len(flag)-1)
            eq['constraint'].append(rand)

    constraint_set = set(flatten([
        eq['constraint'] for eq in constraints
    ]))

    if len(flag) != len(constraint_set):
        print("Not all values represented")
        quit()

    return constraints

cs_pairs = []
constraints = generate_constraints(len(flag), 20)
for eq in constraints:
    flag_map = list(map(flagmap, eq['constraint']))
    cs_pairs.append((eq['constraint'], sum(flag_map)))

template = f'''
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define FLAG "{flag}"
#define FLAGLEN sizeof(FLAG)
char flag[FLAGLEN+1];

{generate_function(cs_pairs)}

int main(void){{
    read(0, flag, FLAGLEN);
    if (check()) puts("Flag");
    else puts("Not flag");
    return 0;
}}
'''

print(template)
