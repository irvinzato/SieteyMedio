import os
import time
import sys
from random import randint, uniform, random

def inicio():
	tid = os.fork()
	if not(tid):  #hijo
		print("************************************************")
		print(os.getpid(),":  Soy el Hijo Compilando...........")
		os.execlp("gcc","gcc","sieteymedio.c")
		os.exit(0)

	else:
		os.wait()
		print("************************************************")
		print("Soy el papa y estoy ejecutando el programa que mi hijo compilo*********************")
		os.execlp("./a.out","a.out")
		print("************************************************")
		os.exit(0)
inicio()