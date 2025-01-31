#include <windows.h>
#include <iostream>

void listDrives() {
    DWORD drives = GetLogicalDrives();
    for (int i = 0; i < 26; ++i) {
        if (drives & (1 << i)) {
            std::cout << "Drive " << char('A' + i) << ":\\ is available.\n";
        }
    }
}

int main() {
    listDrives();
    return 0;
}
