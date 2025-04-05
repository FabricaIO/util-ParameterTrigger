#include "ParameterTrigger.h"

/// @brief Gets the values of all parameters std::vector<std::pair<String, String>>
/// @return The values of the parameters as a map
std::map<String, std::map<String, double>> ParameterTrigger::getParameterValues() {
	std::map<String, std::map<String, double>> result;
	for (const auto& p : parameter_config.Parameters) {
		std::vector<SensorManager::measurement>::iterator i = find_if(SensorManager::measurements.begin(), SensorManager::measurements.end(), [&p](const SensorManager::measurement m) {
			return (m.name == p.first) && (m.parameter == p.second);
		});
		if (i != SensorManager::measurements.end()){
			if (result.count((*i).name) > 0){
				result[(*i).name][(*i).parameter] = (*i).value;
			} else {
				result[(*i).name] = {{(*i).parameter, (*i).value}};
			}
		}
	}
	return result;
}

/// @brief Gets the names of all available sensors and their parameters
/// @return A map containing all available sensor names and their parameters
std::map<String, std::vector<String>> ParameterTrigger::listAllParameters() {
	std::map<String, std::vector<String>> result;
	std::vector<Sensor*> sensors = SensorManager::getSensors();
	std::map<String, std::map<int, String>> output;
	for (int i = 0; i < sensors.size(); i++) {
		std::vector<String> parameters;
		for (auto const &p : sensors[i]->Description.parameters) {
			parameters.push_back(p);
		}
		result[sensors[i]->Description.name] = parameters;
	}
	return result;
}