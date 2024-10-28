// Read files and prints top k word by frequency

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <chrono>
#include <future>
#include <execution>



const size_t TOPK = 10;

using Counter = std::map<std::string, std::size_t>;

void count_words(std::istream& stream, Counter*);

void test(const std::string&);
void print_topk(std::ostream& stream, const Counter&, const size_t k);

thread_local Counter freq_dict;

int main(int argc, char *argv[]) {
//
//   
//   if (argc < 2) {
//       std::cerr << "Usage: topk_words [FILES...]\n";
//       return EXIT_FAILURE;
//   }
//
//   std::vector<std::pair<std::future<void>, Counter*>> tasks;
//
//   auto start = std::chrono::high_resolution_clock::now();
//   for (int i = 1; i < argc; ++i) {
//       std::ifstream input{argv[i]};
//       if (!input.is_open()) {
//           std::cerr << "Failed to open file " << argv[i] << '\n';
//           return EXIT_FAILURE;
//       }
//       Counter* c = new Counter;
//       tasks.push_back(std::pair<std::future<void>, Counter*>(std::async(count_words, std::ref(input), c), c));
//   };
//   std::cout << "!";
//
//   for (int i = 0; i<tasks.size(); i++)
//   {
//       tasks[i].first.wait();   
//   }
//
//
//
//   Counter* main_counter = new Counter;
//   for (int i = 0; i<tasks.size(); i++)
//   {
//       main_counter->merge(*(tasks[i].second));
//       delete tasks[i].second;
//   }
//   
//
//   print_topk(std::cout, std::move(*main_counter), TOPK);   
//   auto end = std::chrono::high_resolution_clock::now();
//   auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//   std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";

while (true)
{
    /* code */
}

}

std::string tolower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
};

void count_words(std::istream& stream, Counter* counter) {
    std::cout << "a";
    std::for_each(std::istream_iterator<std::string>(stream),
                  std::istream_iterator<std::string>(),
                  [counter](const std::string &s) { std::cout << "1"; ++(*counter)[tolower(s)];  });    
}

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
        std::begin(words), std::begin(words) + k, std::end(words),
        [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
        std::begin(words), std::begin(words) + k,
        [&stream](const Counter::const_iterator &pair) {
            stream << std::setw(4) << pair->second << " " << pair->first
                      << '\n';
        });
}