import sys
import time
from datetime import datetime
import random, re
import subprocess

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

    try:
        process = subprocess.run(["./connect4", "{}".format(size_line), "{}".format(size_column)],
                                capture_output=True, universal_newlines=True, input="\n".join(str(x) for x in test_cases), timeout=5)
    except subprocess.TimeoutExpired:
        print(test_cases[0:20])
        return False
    else:
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


def progressbar(it, prefix="", size=60, out=sys.stdout):
    count = len(it)

    def show(j):
        x = int(size*j/count)
        print("{}[{}{}] {}/{}".format(prefix, u"█"*x, "."*(size-x), j, count),
              end='\r', file=out, flush=True)
    show(0)
    for i, item in enumerate(it):
        yield item
        show(i+1)
    print("\n", flush=True, file=out)


if __name__ == "__main__":
    test_it = 0
    test_fail = 0

    print("Start simulation on 6 x 7")
    for i in progressbar(range(10000), "Running tests 6x7: ", 40):
        test_it += 1
        if not main(6, 7):
            test_fail += 1

    # print("Start simulation on 10 x 10")
    # for i in progressbar(range(10000), "Running tests 10x10: ", 40):
    #     test_it += 1
    #     if not main(10, 10):
    #         test_fail += 1
    print("tests: {} | success: {} | fail: {} | fail rate: {}%".format(test_it, test_it - test_fail, test_fail, (100 * test_fail) / test_it))