#include <iostream>
#include <string>
#include <chrono>

// 文字列のコピー時間を計測する関数
void copyTime(const std::string& str) 
{
    auto start = std::chrono::high_resolution_clock::now();
    std::string copy = str;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "コピーにかかった時間: " << duration << " マイクロセカンド" << std::endl;
}

// 文字列の移動時間を計測する関数
void moveTime(std::string&& str)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::string moved = std::move(str);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "移動にかかった時間: " << duration << " マイクロセカンド" << std::endl;
}

int main() 
{
    std::string a(100000, 'a'); // 100000文字の初期化

    printf("100,000文字を移動とコピーで比較しました。\n");


    copyTime(a);
    moveTime(std::move(a));

    return 0;
}
