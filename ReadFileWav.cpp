#include <iostream>
#include <fstream>
#include <string>

// Define the WAV header structure
struct WAVHeader {
    char chunkID[4];
    int chunkSize;
    char format[4];
    char subchunk1ID[4];
    int subchunk1Size;
    short audioFormat;
    short numChannels;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    char subchunk2ID[4];
    int subchunk2Size;
};

// Function to read WAV header from file
bool readWAVHeader(const std::string& filename, WAVHeader& header) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return false;
    }

    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    file.close();

    return true;
}

int main() {
    const std::string filename = "input/20.wav";

    WAVHeader header;

    // Read WAV header from file
    if (!readWAVHeader(filename, header)) {
        return 1;
    }

    // Print out the header information
    std::cout << "ChunkID: " << std::string(header.chunkID, 4) << std::endl;
    std::cout << "ChunkSize: " << header.chunkSize << std::endl;
    std::cout << "Format: " << std::string(header.format, 4) << std::endl;
    std::cout << "Subchunk1ID: " << std::string(header.subchunk1ID, 4) << std::endl;
    std::cout << "Subchunk1Size: " << header.subchunk1Size << std::endl;
    std::cout << "AudioFormat: " << header.audioFormat << std::endl;
    std::cout << "NumChannels: " << header.numChannels << std::endl;
    std::cout << "SampleRate: " << header.sampleRate << std::endl;
    std::cout << "ByteRate: " << header.byteRate << std::endl;
    std::cout << "BlockAlign: " << header.blockAlign << std::endl;
    std::cout << "BitsPerSample: " << header.bitsPerSample << std::endl;
    std::cout << "Subchunk2ID: " << std::string(header.subchunk2ID, 4) << std::endl;
    std::cout << "Subchunk2Size: " << header.subchunk2Size << std::endl;

    return 0;
}
