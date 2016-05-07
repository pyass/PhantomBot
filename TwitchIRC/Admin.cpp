/**
    Admin.cpp
    PhantomBot Project
    By: Robert F. (Phantom139)
    Built on Ubuntu 14.04.10 LTS
**/

#include "Admin.h"

Admin::Admin() {
	UpdateAdminList();
}

Admin::~Admin() {

}

bool Admin::CheckAdminStatus(std::string username) {
	for(int i = 0; i < adminList.size(); i++) {
		if(username.compare(adminList[i]) == 0) {
			return true;
		}
	}
	return false;
}

void Admin::UpdateAdminList() {
    adminList.clear();
	std::fstream f("adminusers.txt", std::ios::in);
	char line[512];
	while(!f.eof()) {
		f.getline(line, 512);
		adminList.push_back(line);
		memset(&line[0], 0, sizeof(line));
	}
}
