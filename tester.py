from datetime import datetime
import random, re
import subprocess
from time import sleep


def escape_ansi(line):
    ansi_escape = re.compile(r'(?:\x1B[@-_]|[\x80-\x9F])[0-?]*[ -/]*[@-~]')
    return ansi_escape.sub('', line)

def generate_random_numbers(size_line: int, size_column: int) -> int :
    test_cases = []
    for i in range(size_line * size_column):
        input_nb = random.randint(0, size_column - 1)
        test_cases.append(input_nb)
    return test_cases


def main(size_line: int, size_column: int):
    test_cases = generate_random_numbers(size_line, size_column)

    process = subprocess.run(["./connect4", "{}".format(size_line), "{}".format(size_column)],
                             capture_output=True, universal_newlines=True, input="\n".join(str(x) for x in test_cases))
    
    if "IA won" not in process.stdout:
        nb_time_prompt = process.stdout.count('>')
        print(process.stdout[process.stdout.rindex("\033[1;1H\033[2J")+len("\033[1;1H\033[2J"):])
        print(test_cases[0:nb_time_prompt])
        process.stdout = process.stdout.replace("> ", "> \n")
        with open(datetime.now().strftime("error_grid_{}_{}_%H_%M_%d_%m_%Y-%f.log".format(size_line, size_column)), "w") as f:
            f.write(escape_ansi(process.stdout))
            f.write("{}".format(test_cases[0:nb_time_prompt]))
            f.close()
        return False
    return True

if __name__ == "__main__":
    print("Start simulation on 6 x 7")
    i = 0
    while i < 500:
        main(6, 7)
        i += 1

    print("Start simulation on 10 x 10")
    i = 0
    while i < 500:
        main(10, 10)
        i += 1
