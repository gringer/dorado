#include "sequence_utils.h"

#include <array>
#include <cmath>
#include <numeric>
#include <vector>

namespace utils {

float mean_qscore_from_qstring(const std::string& qstring) {
    float totalScore = 0;
    for (auto qchar : qstring) {
      float qscore = static_cast<float>(qchar - 33);
      totalScore += std::pow(10.f, -qscore/10.f);
    }
    return(qstring.empty() ? 0 : -10.0f * log10(totalScore / qstring.length()));
}

} // namespace utils
