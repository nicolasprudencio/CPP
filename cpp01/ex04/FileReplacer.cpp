/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:15:43 by nicolas           #+#    #+#             */
/*   Updated: 2024/08/06 23:49:03 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::string newLine;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			// Adiciona a parte da linha antes da ocorrência de s1
			newLine += line.substr(0, pos);
			// Adiciona s2 no lugar de s1
			newLine += s2;
			// Avança a posição na linha além de s1
			line = line.substr(pos + s1.length());
			// Reinicia pos para começar a procurar novamente do início da nova linha
			pos = 0;
		}
		// Adiciona qualquer parte restante da linha que não contenha s1
		newLine += line;
		outputFile << newLine << std::endl;
	}

	inputFile.close();
	outputFile.close();
}

int haveReadPermissionsInFile(std::string filename) {
	std::ifstream fileCheck(filename.c_str());
	if (!fileCheck.is_open()) {
		std::cerr << "Error: No read permission for file " << filename << std::endl;
		return false;
	}
	fileCheck.close();
	return true;
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Error: Usage --> " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	 if (!haveReadPermissionsInFile(filename)) {
		return 1;
	}


	if (s1.empty()) {
		std::cerr << "Error: string1 cannot be empty" << std::endl;
		return 1;
	}

	replaceInFile(filename, s1, s2);

	return 0;
}