#include "ParameterTrigger.h"

/// @brief Gets the values of all parameters
/// @return The values of the parameters as a map
std::map<String, double> ParameterTrigger::getParameterValues() {
	std::map<String, double> result;
	for (const auto& m : SensorManager::measurements) {
		if (std::find(parameter_config.Parameters.begin(), parameter_config.Parameters.end(), m.parameter) != parameter_config.Parameters.end()) {
			result.insert({m.parameter, m.value});
		}
	}
	return result;
}

/// @brief Gets the names of all available parameters
/// @return A vector containing all available parameters
std::vector<String> ParameterTrigger::listAllParameters() {
	std::vector<String> result(SensorManager::measurements.size());
	for (const auto& m : SensorManager::measurements) {
		if (std::find(parameter_config.Parameters.begin(), parameter_config.Parameters.end(), m.parameter) != parameter_config.Parameters.end()) {
			result.push_back(m.parameter);
		}
	}
	return result;
}