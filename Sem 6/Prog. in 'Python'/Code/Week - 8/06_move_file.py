# Move Files to a Different Directory Using shutil
# Write a Python program that moves files from one folder to another using shutil.move().

print("Week 8 - Experiment 6")
print("Amit Singhal | 11614802722")

import shutil

source = "move_me.txt"
destination = "backup/move_me.txt"

shutil.move(source, destination)
print(f"Moved {source} to {destination}")
