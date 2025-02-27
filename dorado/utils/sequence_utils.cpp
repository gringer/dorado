#include "sequence_utils.h"

#include <array>
#include <cmath>
#include <numeric>
#include <vector>

namespace utils {

float mean_qscore_from_qstring(const std::string& qstring) {
    if (qstring.empty()) {
        return 0;
    }

    std::vector<float> scores;
    scores.reserve(qstring.length());
    std::transform(qstring.begin(), qstring.end(), std::back_inserter(scores),
                   [](const char& qchar) {
                       float qscore = static_cast<float>(qchar - 33);
                       return std::pow(10.f, -qscore / 10.f);
                   });
    float mean_error = std::accumulate(scores.begin(), scores.end(), 0.f) / scores.size();
    float mean_qscore = -10.0f * log10(mean_error);
    mean_qscore = std::min(90.0f, std::max(1.0f, mean_qscore));
    return mean_qscore;
}

}  // namespace utils