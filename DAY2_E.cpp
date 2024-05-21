// Juan
#include <bits/stdc++.h>
using namespace std;

// SOAL E
int main() {
  int x, y;
  cin >> x >> y;
  int a, b;
  cin >> a >> b;
  bool papan[x+1][x+1];
  for (int i = 0; i < x+1; i++) {
    for (int j = 0; j < x+1; j++) {
      papan[i][j] = false;
    }
  }
  papan[a][b] = true;
  for (int i = 0; i < y; i++) {
    int c, d;
    cin >> c >> d;
    papan[c][d] = true;
  }
  int moves = 0;
  // Gerak ke kanan
  for (int i = a+1; i < x+1; i++) {
    if (papan[i][b]) {
      break;
    }
    moves++;
  }

  // Gerak ke kiri
  for (int i = a-1; i > 0; i--) {
    if (papan[i][b]) {
      break;
    }
    moves++;
  }

  // Gerak ke atas
  for (int i = b+1; i < x+1; i++) {
    if (papan[a][i]) {
      break;
    }
    moves++;
  }

  // Gerak ke bawah
  for (int i = b-1; i > 0; i--) {
    if (papan[a][i]) {
      break;
    }
    moves++;
  }

  // Gerak ke kanan bawah
  int posX = a+1;
  int posY = b-1;
  while (posX < x+1 && posY > 0 && !papan[posX][posY]) {
    moves++;
    posX++;
    posY--;
  }

  // Gerak ke kiri bawah
  posX = a-1;
  posY = b-1;
  while (posX > 0 && posY > 0 && !papan[posX][posY]) {
    moves++;
    posX--;
    posY--;
  }

  // Gerak ke kanan atas
  posX = a+1;
  posY = b+1;
  while (posX < x+1 && posY < x+1 && !papan[posX][posY]) {
    moves++;
    posX++;
    posY++;
  }
 
  // Gerak ke kiri atas
  posX = a-1;
  posY = b+1;
  while (posX > 0 && posY < x+1 && !papan[posX][posY]) {
    moves++;
    posX--;
    posY++;
  }
  cout << moves;
}

/*// SOAL G
int main() {
  int n;
  cin >> n;
  int num[n], doub[n], rare[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    doub[i] = num[i] * 2;
    rare[i] = sqrt(doub[i]) + 1;
  }
  
  for (int i = 0; i < n; i++) {
    if (doub[i] % rare[i] == 0) {
      cout << "YA" << "\n";
    } else {
      cout << "TIDAK" << "\n";
    }
  } 
}*/

/* // SOAL C
int main() {
	int x;
  cin >> x;
  int y[x], z[x];
  for (int i = 0; i < x; i++) {
    cin >> y[i] >> z[i];
  }
  
  int genTime = 80;
  int gamTime = 65;
  int conTime = 105;
  
  
  
}*/

/* // SOAL H
int main() {
  int n;
  cin >> n;
  int arah[n];
  int xPutar[n];
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp >> xPutar[i];
    if (temp == "timur") { 
      arah[i] = 0;
    } else if (temp == "selatan") {
      arah[i] = 1;
    } else if (temp == "barat") {
      arah[i] = 2;
    } else {
      arah[i] = 3;
    }
  }
  
  for (int i = 0; i < n; i++) {
    xPutar[i] = xPutar[i]%4;
    arah[i] = (arah[i] + xPutar[i]) % 4;
  }
  
  for (int i = 0; i < n; i++) {
    if (arah[i] == 0) { 
      cout << "timur" << "\n";
    } else if (arah[i] == 1) {
      cout << "selatan" << "\n";
    } else if (arah[i] == 2) {
      cout << "barat" << "\n";
    } else {
      cout << "utara" << "\n";
    }
  }
}*/

