# 🔐 Random Password Generator (C)

This project is a password generator written in C, supporting different password creation modes: 1-**Only LowerCase Letters**, 2-**LowerCase and UpperCase Letters**, 3-**LowerCase, UpperCase and Numbers**, and 4-**Lower, Upper, Numbers and Symbols**. Passwords can have variable lengths defined by the user. Generated passwords will be scored based on their length and character composition.

## ⚙️ How it works

The program asks the user for two parameters:
1. Password length
2. Desired strength level:
   - 1 → Weak (lowercase letters only)
   - 2 → Medium (lowercase and uppercase letters)
   - 3 → Strong (letters and digits)
   - 4 → Very Strong (letters, digits, and symbols)

Example usage:

```bash
Enter password length: 12
Enter strength level (1 to 4): 4
Generated password: Gv#8dP$k1@zL
```

## 🧪 Compilation and execution

Linux / macOS
```bash
gcc password_generator.c -o password_generator
./password_generator
```
Windows (MinGW)
```bash
gcc password_generator.c -o password_generator.exe
password_generator.exe
```
