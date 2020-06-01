#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    vector<vector<string>> diary(31);
    int month_num = 0;
    string command;
    int i;
    string s;

    for (int k = 0; k < Q; ++k) {
        cin >> command;
        if (command == "ADD") {
            cin >> i >> s;
            --i;
            diary[i].push_back(s);
        } else if (command == "DUMP") {
            cin >> i;
            --i;
            cout << diary[i].size() << " ";
            for (auto j : diary[i]) {
                cout << j << " ";
            }
            cout << endl;
        } else if (command == "NEXT") {
            if (diary.size() == 31 && month_num % 12 == 0) {
                // текущий месяц - январь, 31 день, следующий - февраль, 28 дней
                // дела с 29, 30, 31 дня переносятся на 28

                // создаём новый вектор
                // копируем в новый вектор всё, что было в старом до 28 дней
                vector<vector<string>> new_diary(28);
                for (int l = 0; l < 28; ++l) {
                    new_diary[l] = diary[l];
                }
                // 29, 30, 31 дни записываем в 28
                for (int l = 28; l < 31; ++l) {
                    new_diary[27].insert(end(new_diary[27]), begin(diary[l]), end(diary[l]));
                }
                // заменяем старый на новый
                diary = new_diary;
            } else if (diary.size() == 31 && (month_num % 12 == 6 || month_num % 12 == 11)) {
                // текущий месяц - июль или декабрь
                // дела остаются без изменений
            } else if (diary.size() == 31 && month_num % 12 != 0) {
                // текущий месяц - не январь, 31 день, следующий - 30
                // дела с 31 дня переносятся на 30

                diary[29].insert(end(diary[29]), begin(diary[30]), end(diary[30]));
                diary.resize(30);
            } else if (diary.size() == 28 || diary.size() == 30) {
                // текущий месяц - 28 или 30 дней
                // новые дни пустые

                diary.resize(31);
            }
            ++month_num;
        }
    }

    return 0;
}