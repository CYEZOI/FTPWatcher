#include <windows.h>
#include <wininet.h>
#include <iostream>

#pragma comment(lib, "wininet.lib")

int main() {
    HINTERNET hInternet = InternetOpen(TEXT("FTP"), INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if(hInternet) {
        HINTERNET hFtpSession = InternetConnect(hInternet, TEXT("10.89.71.90"), INTERNET_DEFAULT_FTP_PORT, TEXT("cyez"), TEXT(""), INTERNET_SERVICE_FTP, 0, 0);
        if(hFtpSession) {
            if(FtpGetFile(hFtpSession, TEXT("1.txt"), TEXT("1.txt"), FALSE, FILE_ATTRIBUTE_NORMAL, FTP_TRANSFER_TYPE_BINARY, 0)) {
                std::cout << "File downloaded successfully!" << std::endl;
            } else {
                std::cerr << "Error downloading file: " << GetLastError() << std::endl;
            }
            InternetCloseHandle(hFtpSession);
        }
        InternetCloseHandle(hInternet);
    }
    return 0;
}
