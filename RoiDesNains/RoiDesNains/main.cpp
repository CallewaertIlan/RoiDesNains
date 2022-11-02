#include "Framework.h"

int main()
{
    Menu menu = Menu();
    menu.OnUpdate();
    return 0;
}

//int main()
//{
//    auto start = chrono::steady_clock::now();
//
//    // do some stuff here
//    Sleep(3000);
//
//    auto end = chrono::steady_clock::now();
//
//    cout << "Elapsed time in milliseconds: "
//        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
//        << " ms" << endl;
//
//    return 0;
//}