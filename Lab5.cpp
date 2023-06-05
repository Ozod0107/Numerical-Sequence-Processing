#include <iostream>
#include <cmath>

using namespace std;
const int MAX_SIZE = 100;

int countLessC(double arr[], int n, double c) 
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < c) 
        {
            count++;
        }
    }
    return count;
}

int Negative(double arr[], int n, bool* found)
{
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < 0) 
        {
            *found = true;
            break;
        }
        sum += static_cast<int>(arr[i]);
    }
    if (*found) 
    {
        return sum;
    }
    else 
    {
        return -1;
    }
}

void transformArray(double arr[], int n) 
{
    double maxElem = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > maxElem)
        {
            maxElem = arr[i];
        }
    }
    int countMaxElem = 0;

    for (int i = 0; i < n; i++) 
    {
        if (abs(arr[i] - maxElem) <= maxElem * 0.2) 
        {
            countMaxElem++;
        }
    }
    double tempArr[MAX_SIZE];
    int indexMax = 0, indexOther = countMaxElem;

    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i] - maxElem) <= maxElem * 0.2) 
        {
            tempArr[indexMax] = arr[i];
            indexMax++;
        }
        else 
        {
            tempArr[indexOther] = arr[i];
            indexOther++;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        arr[i] = tempArr[i];
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    int n;
    double arr[MAX_SIZE];

    cout << "Введите размер массива (не более " << MAX_SIZE << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE) 
    {
        cout << "Ошибка! Недопустимый размер массива." << endl;
        return 0;
    }

    cout << "Введите " << n << " вещественных чисел:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while (true)
        {
            if (cin.fail() || cin.get() != '\n')
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка: введено некорректное значение! Повторите ввод.\n";
                cin >> arr[i];
            }
            else
                break;
        }


    }
    double c;
    cout << "Введите число C: ";
    cin >> c;
    bool foundNegative;
    // Задание №1
    cout << "Количество элементов массива, меньших C: " << countLessC(arr, n, c) << endl;
    // Задание №2
    int NegativeResult = Negative(arr, n, &foundNegative);
      if (foundNegative == true)
      {
        cout << "Сумма целых частей элементов массива, расположенных после последнего отрицательного элемента: " << NegativeResult << endl;
      }
      else
      {
        cout << "В массиве нет отрицательных элементов." << endl;
      }
    // Задание №3
    transformArray(arr, n);

    cout << "Преобразованный массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    double summ=0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
        {
            summ += arr[i];
        }
    }
    double zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;


    }
    return 0;
}