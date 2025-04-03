#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Estrutura para armazenar cada bloco e sua contagem
struct HashNode {
    string key;
    int count;
};

// Classe da Tabela Hash usando encadeamento externo
class HashTable {
private:
    static const int TABLE_SIZE = 10007; // Tamanho primo para reduzir colisões
    vector<list<HashNode>> table;

    // Função de espalhamento usando metodo de Horner
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % TABLE_SIZE;
        }
        return hash;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(const string& key) {
        int index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                node.count++;
                return;
            }
        }
        table[index].push_back({key, 1});
    }

    void writeToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Erro ao abrir arquivo de saída!" << endl;
            return;
        }
        for (const auto& bucket : table) {
            for (const auto& node : bucket) {
                file << node.key << " " << node.count << endl;
            }
        }
        file.close();
    }
};

// Função para processar o arquivo do genoma
void processGenomeFile(const string& inputFile, const string& outputFile) {
    ifstream file(inputFile);
    if (!file) {
        cerr << "Erro ao abrir o arquivo do genoma!" << endl;
        return;
    }

    HashTable hashTable;
    string line;

    while (getline(file, line)) {
        if (line.size() < 60) continue; // Ignora a última linha incompleta

        for (size_t i = 0; i + 6 <= line.size(); i += 6) {
            string block = line.substr(i, 6);
            hashTable.insert(block);
        }
    }

    file.close();
    hashTable.writeToFile(outputFile);
}

int main() {
    string inputFile = "../data/genoma.txt";  // Arquivo de entrada
    string outputFile = "../data/output.txt"; // Arquivo de saída

    processGenomeFile(inputFile, outputFile);

    cout << "Processamento concluído! Verifique o arquivo " << outputFile << endl;
    return 0;
}
