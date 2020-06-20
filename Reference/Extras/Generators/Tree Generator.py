from random import randint
from sys import stdout
import subprocess

n = randint(2, 10)
cout = f"{n}\n"
for i in range(n):
    if i:
        cout += " "
    cout += f"{randint(1, 10)}"

cout += "\n"

for i in range(2, n + 1):
    u = i
    v = randint(1, i - 1)
    cout += f"{u} {v}\n"

with open('in', 'r') as f: cout = f.read()

stdout.write(cout)
stdout.write("================\n")

with open('in', 'w+') as f: f.write(cout)

# subprocess.run("g++ -std=c++14 sol.cpp -o sol", shell=True)
# subprocess.run("g++ -std=c++14 brute.cpp -o brute", shell=True)
subprocess.run("./brute < in > outb && ./sol < in > outs", shell=True)
with open('outb', 'r') as f:
    ans1 = f.read()
ans1 = ans1.split('\n')[:-1]
with open('outs', 'r') as f:
    ans2 = f.read()

ans2 = ans2.split('\n')[:-1]
for i in range(max(len(ans1), len(ans2))):
    left = "--"
    right = "--"
    if (i < len(ans1)): left = ans1[i]
    if (i < len(ans2)): right = ans2[i]
    stdout.write(f"{left: <7} |  {right}\n")
stdout.write('\n')

# subprocess.run("diff outb outs", shell=True)