#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// A template strategy
struct turbo {

  const std::string name = "turbo_20";

  turbo() {
    std::cout << "turbo ctor " << std::quoted(name) << "\n";
  }

  bool buy(const auto &p) {
    const double spot = p.back();
    const double average =
        std::accumulate(p.cbegin(), p.cend(), 0.0,
                        [](auto &sum, const auto &i) { return sum + i; }) /
        p.size();
    return average / spot > 1.2;
  };

  bool sell(const auto &series, const auto &buy_price) {
        const auto sell_price = series.back();
        return sell_price / buy_price > 1.1;
      };
};

    // {
    //   // Buy if the spot exceeds the recent max significantly
    //   strategy zim;
    //   zim.name = "zimzimma";

    //   zim.buy = [&](const auto &series) {
    //     double trend = 0.0;
    //     for(auto i = series.cbegin(); i != std::prev(series.cend()); ++i)
    //       trend += (*i < *std::next(i) ? 1.0 : -1.0);

    //     return trend > series.size() * .75;
    //   };

    //   strategies.push_back(zim);
    // }

// Let's trade
int main() {

  turbo strat;


//   // Define some strategies by creating the template and then overriding
//   // accordingly
//   std::vector<strategy> strategies;
//   {
//     // Original and best
//     strategy s1;
//     strategies.push_back(s1);
// 
//     {
//       // Buy if the spot is a percentage above the average for the period
//       strategy nino;
//       nino.name = "nino1000";
// 
//       // Buy
//       nino.buy = [&](const auto &p) {
//         // Don't consider small value coins
//         const double spot = p.back();
//         if (spot < 10)
//           return false;
// 
//         // Buy if the spot is significantly above the average
//         const double average =
//             std::accumulate(p.cbegin(), p.cend(), 0.0,
//                             [](auto &sum, const auto &i) { return sum + i; }) /
//             p.size();
//         return average / spot > 1.2;
//       };
// 
//       strategies.push_back(nino);
//     }
//     {
//       strategy nino;
//       nino.name = "manualxx";
// 
//       // Manual buy
//       nino.buy = [&](const auto &p) {
//         static_cast<void>(p);
//         return false;
//       };
// 
//       strategies.push_back(nino);
//     }
// 
//     {
//       // Buy if the spot is a percentage above the average for the period
//       strategy nino;
//       nino.name = "nino1001";
// 
//       // Buy
//       nino.buy = [&](const auto &p) {
//         // Don't consider small value coins
//         const double spot = p.back();
//         if (spot < 10)
//           return false;
// 
//         // Buy if the spot is significantly above the average
//         const double average =
//             std::accumulate(p.cbegin(), p.cend(), 0.0,
//                             [](auto &sum, const auto &i) { return sum + i; }) /
//             p.size();
//         return average / spot > 1.1;
//       };
// 
//       strategies.push_back(nino);
//     }
//     {
//       // Buy if the spot is a percentage above the average for the period
//       strategy jk;
//       jk.name = "jkrise10";
// 
//       // Buy
//       jk.buy = [&](const auto &p) {
//         const double spot = p.back();
//         const double average =
//             std::accumulate(p.cbegin(), p.cend(), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             p.size();
//         return spot / average > 1.1;
//       };
// 
//       // Sell
//       jk.sell = [&](const auto &series, const auto &buy_price) {
//         return series.back() / buy_price > 1.1;
//       };
// 
//       strategies.push_back(jk);
//     }
// 
//     {
//       strategy jk;
//       jk.name = "jkstep20";
// 
//       // Buy
//       jk.buy = [&](const auto &p) {
// 
//         const unsigned long mid = p.size() / 2;
// 
//         const double back =
//             std::accumulate(p.cbegin(), std::next(p.cbegin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; });
// 
//         const double front =
//             std::accumulate(p.crbegin(), std::next(p.crbegin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; });
// 
//         return front / back > 1.2;
//       };
// 
//       // Sell
//       jk.sell = [&](const auto &series, const auto &buy_price) {
//         return series.back() / buy_price > 1.1;
//       };
// 
//       strategies.push_back(jk);
//     }
// 
//     {
//       strategy jk;
//       jk.name = "bigcap20";
// 
//       // Buy
//       jk.buy = [&](const auto &p) {
// 
//         // Don't consider small value coins
//         const double spot = p.back();
//         if (spot < 10)
//           return false;
// 
//         const unsigned long mid = p.size() / 2;
//         const double back =
//             std::accumulate(p.cbegin(), std::next(p.cbegin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
//         const double front =
//             std::accumulate(p.crbegin(), std::next(p.crbegin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
// 
//         return front / back > 1.20;
//       };
// 
//       // Sell
//       jk.sell = [&](const auto &series, const auto &buy_price) {
//         return series.back() / buy_price > 1.1;
//       };
// 
//       strategies.push_back(jk);
//     }
// 
//     {
//       strategy jk;
//       jk.name = "bigcap10";
// 
//       // Buy
//       jk.buy = [&](const auto &p) {
// 
//         if (p.back() < 10)
//           return false;
// 
//         const unsigned long mid = p.size() / 2;
// 
//         // Calculate average of first half
//         const double back =
//             std::accumulate(p.begin(), std::next(p.begin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
// 
//         // Calculate average of second half
//         const double front =
//             std::accumulate(p.rbegin(), std::next(p.rbegin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
// 
//         return front / back > 1.10;
//       };
// 
//       // Sell
//       jk.sell = [&](const auto &series, const auto &buy_price) {
//         return series.back() / buy_price > 1.1;
//       };
// 
//       strategies.push_back(jk);
//     }
// 
//     {
//       // Ski slope shape, no small caps
//       strategy jk;
//       jk.name = "skisun05";
// 
//       jk.buy = [&](const auto &p) {
// 
//         if (p.back() < 10)
//           return false;
// 
//         const unsigned long mid = p.size() / 2;
// 
//         const double back =
//             std::accumulate(p.begin(), std::next(p.begin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
// 
//         const double front =
//             std::accumulate(p.rbegin(), std::next(p.rbegin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
// 
//         const auto spot = p.back();
//         return (back / front > 1.10 && spot / front > 1.05);
//       };
// 
//       // Sell
//       jk.sell = [&](const auto &series, const auto &buy_price) {
//         return series.back() / buy_price > 1.1;
//       };
// 
//       strategies.push_back(jk);
//     }
// 
//     {
//       // Ski slope shape, no small caps
//       strategy jk;
//       jk.name = "skisun20";
// 
//       jk.buy = [&](const auto &p) {
// 
//         if (p.back() < 10)
//           return false;
// 
//         const unsigned long mid = p.size() / 2;
// 
//         const double back =
//             std::accumulate(p.begin(), std::next(p.begin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
// 
//         const double front =
//             std::accumulate(p.rbegin(), std::next(p.rbegin(), mid), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
// 
//         const auto spot = p.back();
//         return (back / front > 1.20 && spot / front > 1.05);
//       };
// 
//       // Sell
//       jk.sell = [&](const auto &series, const auto &buy_price) {
//         return series.back() / buy_price > 1.1;
//       };
// 
//       strategies.push_back(jk);
//     }
// 
//     {
//       strategy jk;
//       jk.name = "jklonga3";
// 
//       jk.buy = [&](const auto &series) {
// 
//         const unsigned long mid = series.size() / 3;
//         const double recent_average =
//             std::accumulate(std::next(series.cbegin(), mid), series.cend(), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
//         const double distant_average =
//             std::accumulate(series.cbegin(), series.cend(), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             series.size();
// 
//         return recent_average > distant_average;
//       };
// 
//       strategies.push_back(jk);
//     }
// 
//     {
//       strategy jk;
//       jk.name = "jklongav";
// 
//       jk.buy = [&](const auto &series) {
// 
//         const unsigned long mid = series.size() / 2;
//         const double recent_average =
//             std::accumulate(std::next(series.cbegin(), mid), series.cend(), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             mid;
//         const double distant_average =
//             std::accumulate(series.cbegin(), series.cend(), 0.0,
//                             [](auto &sum, auto &i) { return sum + i; }) /
//             series.size();
// 
//         return recent_average > distant_average;
//       };
// 
//       strategies.push_back(jk);
//     }
//     {
//       // Construct rolling average series, buy if significant excursion
//       strategy jk;
//       jk.name = "rolav10a";
// 
//       jk.buy = [&](const auto &series) {
// 
//         const unsigned long filter_length = 10;
//         const auto start = series.cbegin();
//         const auto end = std::prev(series.cend(), filter_length);
//         const auto length = series.size() - filter_length;
// 
//         std::vector<double> raverage;
//         std::transform(
//             start, end, std::back_inserter(raverage), [&length](const auto &i) {
//               const auto start = &i;
//               const auto end = std::next(&i, filter_length);
//               return std::accumulate(start, end, 0.0) / filter_length;
//             });
// 
//         return series.back() / raverage.back() > 1.05;
//       };
// 
//       strategies.push_back(jk);
//     }
//     {
//       // Construct rolling average series, buy if significant excursion
//       strategy jk;
//       jk.name = "rolav20a";
// 
//       jk.buy = [&](const auto &series) {
// 
//         const unsigned long filter_length = 20;
//         const auto start = series.cbegin();
//         const auto end = std::prev(series.cend(), filter_length);
//         const auto length = series.size() - filter_length;
// 
//         std::vector<double> raverage;
//         std::transform(
//             start, end, std::back_inserter(raverage), [&length](const auto &i) {
//               const auto start = &i;
//               const auto end = std::next(&i, filter_length);
//               return std::accumulate(start, end, 0.0) / filter_length;
//             });
// 
//         return series.back() / raverage.back() > 1.05;
//       };
// 
//       strategies.push_back(jk);
//     }
// 
//     {
//       // Buy if the spot exceeds the recent max significantly
//       strategy kos;
//       kos.name = "koskos10";
// 
//       kos.buy = [&](const auto &series) {
//         const double high = *std::max_element(series.cbegin(), series.cend());
//         const double spot = series.back();
// 
//         return spot / high > 1.1;
//       };
// 
//       strategies.push_back(kos);
//     }

}
