#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    char str[1001][1001]{};
    for (int i = 0; i < n; i++){
        cin >> str[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (strcmp(str[j], str[j + 1]) > 0){
                char temp[1001]{};
                strcpy(temp, str[j + 1]);
                strcpy(str[j + 1], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << str[i] << endl;
    }
}