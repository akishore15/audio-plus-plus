#include <mntent.h>
#include <iostream>

void listDrives() {
    FILE *fp = setmntent("/etc/mtab", "r");
    if (fp == NULL) {
        perror("setmntent");
        return;
    }
    struct mntent *mnt;
    while ((mnt = getmntent(fp)) != NULL) {
        std::cout << "Drive " << mnt->mnt_dir << " of type " << mnt->mnt_type << "\n";
    }
    endmntent(fp);
}

int main() {
    listDrives();
    return 0;
}
