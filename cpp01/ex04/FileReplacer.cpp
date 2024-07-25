#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
	// Abre o arquivo de entrada
	std::ifstream inputFile(filename.c_str());
	if (!inputFile) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}

	// Cria o nome do arquivo de saída
	std::string newFilename = filename + ".replace";
	std::ofstream outputFile(newFilename.c_str());
	if (!outputFile) {
		std::cerr << "Error: Could not create file " << newFilename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		// Substitui todas as ocorrências de s1 por s2
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.replace(pos, s1.length(), s2);
			pos += s2.length(); // Avança para além da nova string
		}
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];


	if (s1.empty()) {
		std::cerr << "Error: string1 cannot be empty" << std::endl;
		return 1;
	}

	replaceInFile(filename, s1, s2);

	return 0;
}
