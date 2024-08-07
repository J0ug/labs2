//Hash-table
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
private:
  // Хеш-таблицы для каждого ряда клавиатуры
  unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
  unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
  unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
public:
  // Функция для проверки, можно ли набрать слово на одном ряду клавиатуры
    bool isRow(const string& word) {
      if (word.empty()) return true;
      char firstRow = tolower(word[0]); // Определяем ряд для первого символа
      for (char c : word) {
        char currentChar = tolower(c);
        // Проверяем, находится ли текущий символ в том же ряду, что и первый
        if (row1.find(firstRow) != row1.end() && row1.find(currentChar) == row1.end()) {
          return false;
        } else if (row2.find(firstRow) != row2.end() && row2.find(currentChar) == row2.end()) {
          return false;
        } else if (row3.find(firstRow) != row3.end() && row3.find(currentChar) == row3.end()) {
          return false;
        }
      }
      return true;
    }
  // Функция для вывода слов, которые можно набрать на одном ряду
  void printOneRow(const vector<string>& words) {
    cout << "Слова, которые можно набрать на одном ряду клавиатуры:\n";
    for (const string& w : words) {
      if (isRow(w)) {
        cout << w << " ";
      }
    }
    cout << endl;
  }
};
int main() {
  Solution checker;
  string word;
  vector<string> words;
  cout << "Введите набор слов, разделенных пробелами:\n";
  getline(cin, word);
  string currentWord;
  for (char c : word) {
    if (c == ' ') {
      words.push_back(currentWord);
      currentWord = "";
    } else {
      currentWord += c;
    }
  }
  words.push_back(currentWord);
  checker.printOneRow(words);
}
