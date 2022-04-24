// using namespace std;

// void menuLoginActivity()
// {
//     system("cls");
//     cout << "Login" << endl;
//     cout << "1. Login" << endl;
//     cout << "2. Register" << endl;
//     cout << "3. Back" << endl;
// }

// // Enumerator
// enum IN
// {

//     // 13 is ASCII for carriage
//     // return
//     IN_BACK = 8,
//     IN_RET = 13

// };

// // Function that accepts the password
// string takePasswdFromUser(char sp = '*')
// {
//     // Stores the password
//     string passwd = "";
//     char ch_ipt;

//     // Until condition is true
//     while (true)
//     {

//         ch_ipt = getch();

//         // if the ch_ipt
//         if (ch_ipt == IN::IN_RET)
//         {
//             cout << endl;
//             return passwd;
//         }
//         else if (ch_ipt == IN::IN_BACK && passwd.length() != 0)
//         {
//             passwd.pop_back();

//             // Cout statement is very
//             // important as it will erase
//             // previously printed character
//             cout << "\b \b";

//             continue;
//         }

//         // Without using this, program
//         // will crash as \b can't be
//         // print in beginning of line
//         else if (ch_ipt == IN::IN_BACK && passwd.length() == 0)
//         {
//             continue;
//         }

//         passwd.push_back(ch_ipt);
//         cout << sp;
//     }
// }

// void login()
// {
//     // Take user name input
//     string userName;
//     cout << "Enter your user name: ";
//     cin >> userName;

//     // Take password input in * character
//     string password;
//     cout << "Enter your password: ";
//     password = takePasswdFromUser();

//     // Open User.bin and read data
// }