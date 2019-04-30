#include <iostream>
#include <assert.h>
using namespace std;

char nibble_to_hex (uint8_t i) {
    assert(0x0 <= i && i <= 0xf);
    char symbols[] = "0123456789abcdef";
    return symbols [i];
}

void print_in_hex (uint8_t byte){
cout << nibble_to_hex (byte >> 4);
cout << nibble_to_hex (byte & 0b00001111);
}

const uint8_t* as_bytes(const void* data) {
return reinterpret_cast<const uint8_t*>(data);
}

void print_in_hex (const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);

        // Для удобства чтения: пробелы между байтам, по 16 байт на строку.
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}

char bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}

void print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit >= 0; bit--) {
        cout << bit_digit(byte, bit);
        if (bit==0)
            return;
    }
}

void print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);

        // Для удобства чтения: пробелы между байтами, по 4 байта на строку.
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}

void cale (uint16_t op1, char operat, uint16_t op2) {
print_in_hex (&op1, sizeof(op1));
cout << ' ' << operat << ' ';
print_in_hex (&op2, sizeof(op2));
cout << ' = ';
uint16_t res;
if (operat == '&')
res = op1 & op2;
if (operat == '|')
res = op1 | op2;
if (operat == '^')
res = op1 ^ op2;

cout << res;
}

struct Student {
 char name[17];
 uint16_t year;
 float average;
 uint8_t gender: 1;
 uint8_t courses;
 Student* starosta;
 };

int main()
{
 Student students [3] = {
     {
         "Nastya", 2018, 4.5, 1, 1, nullptr
     },
     {
         "Misha", 2015, 5.0, 0, 4, &students[0]
     },
     {
         "Marina", 2013, 2.5, 1, 6, &students[0]
     }
};

cout << "Address of students" << '\n';
cout << & students;
cout << '\n' << "Size of students" << '\n';
cout << sizeof (students) << '\n';

 for (Student stud:students)
 {
     cout << "Address of student" << '\n';
     cout << & stud;
     cout << '\n' << "Size of student" << '\n';
     cout << sizeof (stud) << '\n';
 }

     cout << "Adress name of student 2" << '\n' << &students[1].name << '\n';










  /*
uint32_t u8 = 0x42;
cout << "u8 bytes: ";
print_in_hex(&u8, sizeof(u8));
cout << '\n';

uint32_t u16 = 0x42;
cout << "u16 bytes: ";
print_in_hex(&u16, sizeof(u16));
cout << '\n';

uint32_t u32 = 0x42;
cout << "u32 bytes: ";
print_in_hex(&u32, sizeof(u32));
cout << '\n';

print_in_binary(15);



    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');

     */
    return 0;
}
