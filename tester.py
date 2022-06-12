import random, re
import subprocess
from time import sleep


def escape_ansi(line):
    ansi_escape = re.compile(r'(?:\x1B[@-_]|[\x80-\x9F])[0-?]*[ -/]*[@-~]')
    return ansi_escape.sub('', line)

def generate_random_numbers(size_line: int, size_column: int) -> int :
    test_cases = []

    for i in range(size_line * size_column):
        input_nb = random.randint(0, size_column)
        test_cases.append(input_nb)

def main():
    test_cases = []

    for i in range(10 * 10):
        input_nb = random.randint(0, 9)
        test_cases.append(input_nb)

    process = subprocess.run(["./connect4", "10", "10"],
                             capture_output=True, universal_newlines=True, input="\n".join(str(x) for x in test_cases))
    
    if "IA won" not in process.stdout:
        nb_time_prompt = process.stdout.count('>')
        print(process.stdout)
        print(test_cases[0:nb_time_prompt])
        return False
    return True

if __name__ == "__main__":
    print("Start simulation")
    i = 0
    while main():
        print("Simulation {}".format(i))
        i += 1
