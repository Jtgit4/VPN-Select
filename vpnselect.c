#include <stdio.h>
#include <stdlib.h> //this is for the system() function


int main() {

    int selection;
    int ExistingConnection = system("ifconfig tun0 > /dev/null 2>&1"); //used to check for existing VPN connection attached to tun0
    char TerminateVPN;


    //filepath for .ovpn files
    char file_path1 [200] = "/home/kali/Desktop/academy-regular-TCP.ovpn";  
    char file_path2 [200] = "/home/kali/Desktop/academy-regular-UDP.ovpn";
    char file_path3 [200] = "/home/kali/Desktop/HTB_labs.ovpn";
    char file_path4 [200] = "/home/kali/Desktop/offsec.ovpn";
    char file_path5 [200] = "/home/kali/Desktop/competitive_frznram.ovpn";

    printf("\n+-----------------+\n");
    printf("|                 |\n");
    printf("|   \033[1m\033[32mVPN-Selector\033[0m  |\n");
    printf("|                 |\n");
    printf("+-----------------+\n");
    printf("\n\e[1mVPN List\e[0m\n\n");
    printf("[1] Hack The Box - Academy TCP\n");
    printf("[2] Hack The Box - Academy UDP\n");
    printf("[3] Hack The Box - Labs\n");
    printf("[4] Offsec - Proving Grounds\n");
    printf("[5] Hack The Box - Seasonal\n");


    printf("\n\033[1m\033[34mSelect VPN: \033[0m");

    scanf("%d", &selection);
    getchar(); //clear new line character from buffer, without this the scanf function to for TerminateVPN doesn't work.

    
    if (ExistingConnection == 0) {
        // checks for an existing VPN connection bound to TUN)
        printf("\033[1m\033[31m\nThere is an existing VPN connection bound to TUN0!\n\033[0m");
        printf("\nTerminate existing VPN connection(Y) or Exit(E): ");
        scanf("%c", &TerminateVPN);

        if (TerminateVPN == 'E' || TerminateVPN == 'e') {
            return 0; 
        }

        else if (TerminateVPN == 'Y' || TerminateVPN == 'y') {

            system("sudo pkill openvpn");
        }

        else {
            printf("\033[1m\033[31m\\nInvalid selection, existing program!\n\033[0m");
            return 0;
            //Error handling, catches any input that isnt in [E, e, Y, y]
        }
    }

    //Establish a new VPN connection
    switch (selection) {
        case 1: {
            char vpn1[256];
            sprintf(vpn1, "sudo openvpn %s", file_path1);
            printf("Opening connection to %s", file_path1);
            system(vpn1);
            break;
        }
        case 2: {
            char vpn2[256];
            sprintf(vpn2, "sudo openvpn %s", file_path2);
            printf("Opening connection to %s", file_path2);
            system(vpn2);
            break;
        }
        case 3: {
            char vpn3[256];
            sprintf(vpn3, "sudo openvpn %s", file_path3);
            printf("Opening connection to %s", file_path3);
            system(vpn3);
            break;
        }
        case 4: {
            char vpn4[256];
            printf("\nOpening connection to %s\n\n", file_path4);
            sprintf(vpn4, "sudo openvpn %s", file_path4);
            fflush(stdout);
            system(vpn4);
            break;
        }
        case 5: {
            char vpn5[256];
            sprintf(vpn5, "sudo openvpn %s", file_path5);
            printf("Opening connection to %s", file_path5);
            system(vpn5);
            break;
        }
        default: {
            printf("\nInvalid Selection, exiting...\n");
            break;
        }
    }

    return 0;
}