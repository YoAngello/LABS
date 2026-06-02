#include "PasswordError.h"
#include <iostream>
#include <string>

using namespace std;

// Объявление функции из другого файла
string get_password();

int main() {
    cout << "=== ПРОВЕРКА ПАРОЛЯ ===\n" << endl;
    cout << "Требования к паролю:\n";
    cout << "- Длина не менее 9 символов\n";
    cout << "- Содержит буквы в разных регистрах\n";
    cout << "- Содержит хотя бы одну цифру\n";
    cout << "- Не содержит символы: l, I, 1, o, O, 0\n" << endl;

    bool success = false;

    while (!success) {
        try {
            string password = get_password();
            cout << "\n✓ Пароль принят!" << endl;
            cout << "Ваш пароль: " << password << endl;
            success = true;
        }
        catch (const LengthError& e) {
            cerr << "\n✗ " << e.what() << endl;
            cout << "Попробуйте снова.\n" << endl;
            cin.clear();
        }
        catch (const RegisterError& e) {
            cerr << "\n✗ " << e.what() << endl;
            cout << "Используйте и заглавные, и строчные буквы.\n" << endl;
            cin.clear();
        }
        catch (const DigitError& e) {
            cerr << "\n✗ " << e.what() << endl;
            cout << "Добавьте хотя бы одну цифру.\n" << endl;
            cin.clear();
        }
        catch (const ForbiddenLetterError& e) {
            cerr << "\n✗ " << e.what() << endl;
            cout << "Замените символ '" << e.getForbiddenChar()
                << "' на другой.\n" << endl;
            cin.clear();
        }
        catch (const PasswordError& e) {
            cerr << "\n✗ Ошибка пароля: " << e.what() << endl;
            cout << "Попробуйте снова.\n" << endl;
            cin.clear();
        }
        catch (const exception& e) {
            cerr << "\n✗ Неизвестная ошибка: " << e.what() << endl;
            cout << "Попробуйте снова.\n" << endl;
            cin.clear();
        }
    }

    cout << "\nДоступ разрешён!" << endl;

    return 0;
}