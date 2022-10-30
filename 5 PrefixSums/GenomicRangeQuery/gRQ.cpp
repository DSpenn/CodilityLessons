#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> answer(P.size());
  vector<int> a(S.size() + 1);
  vector<int> c(S.size() + 1);
  vector<int> g(S.size() + 1);

  for (size_t i = 0; i < S.size(); i++) {
    a[i + 1] = a[i] + (S[i] == 'A');
    c[i + 1] = c[i] + (S[i] == 'C');
    g[i + 1] = g[i] + (S[i] == 'G');
  }

  for (size_t i = 0; i < P.size(); i++) {
    if (a[Q[i] + 1] - a[P[i]] > 0)
      answer[i] = 1;
    else if (c[Q[i] + 1] - c[P[i]] > 0)
      answer[i] = 2;
    else if (g[Q[i] + 1] - g[P[i]] > 0)
      answer[i] = 3;
    else
      answer[i] = 4;
  }

  return answer;
}


/* // too slow 
#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores(P.size());
  string c;

  for (size_t x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c == "A") {
        scores[x] = 1;
      } else if (c == "C") {
        scores[x] = 2;
      } else if (c == "G") {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    } else {
      c = S.substr(P[x], Q[x] + 1 - P[x]);
      if (c.find("A") != string::npos && c.find("C") != string::npos &&
          c.find("G") != string::npos && c.find("T") != string::npos) {
        scores[x] = 1;
      } else if (c.find("A") != string::npos) {
        scores[x] = 1;
      } else if (c.find("C") != string::npos) {
        scores[x] = 2;
      } else if (c.find("G") != string::npos) {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    }
  }
  return scores;
}
 */




























#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores(P.size());
  string c;

  for (size_t x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c == "A") {
        scores[x] = 1;
      } else if (c == "C") {
        scores[x] = 2;
      } else if (c == "G") {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    } else {
      c = S.substr(P[x], Q[x] + 1 - P[x]);
      char * cstr = new char [c.length()+1];
      std::strcpy (cstr, c.c_str());
      if (strstr(cstr,"A") &&  strstr(cstr,"C") &&
          strstr(cstr,"G") && strstr(cstr,"T")) {
        scores[x] = 1;
      } else if (strstr(cstr,"A")) {
        scores[x] = 1;
      } else if (strstr(cstr,"C")) {
        scores[x] = 2;
      } else if (strstr(cstr,"G")) {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    }
  }
  return scores;
}






// .72

#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <map>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores(P.size());
  string c;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c == "A") {
        scores[x] = 1;
      } else if (c == "C") {
        scores[x] = 2;
      } else if (c == "G") {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    } else {
      c = S.substr(P[x], Q[x] + 1 - P[x]).c_str();
/*       char * cstr = new char [c.length()+1];
        std::strcpy (cstr, c.c_str()); */
      if (strchr(cstr,'A') &&  strchr(cstr,'C') &&
          strchr(cstr,'G') && strchr(cstr,'T')) {
        scores[x] = 1;
      } else if (strchr(cstr,'A')) {
        scores[x] = 1;
      } else if (strchr(cstr,'C')) {
        scores[x] = 2;
      } else if (strchr(cstr,'G')) {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    }
  }
  return scores;
}














// .232


#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores(P.size());
  string c;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c == "A") {
        scores[x] = 1;
      } else if (c == "C") {
        scores[x] = 2;
      } else if (c == "G") {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    } else {
      c = S.substr(P[x], Q[x] + 1 - P[x]);
      if (c.find('A') != string::npos && c.find('C') != string::npos &&
          c.find('G') != string::npos && c.find('T') != string::npos) {
        scores[x] = 1;
      } else if (c.find('A') != string::npos) {
        scores[x] = 1;
      } else if (c.find('C') != string::npos) {
        scores[x] = 2;
      } else if (c.find('G') != string::npos) {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    }
  }
  return scores;
}












// .232

#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores(P.size());
  string c;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c == "A") {
        scores[x] = 1;
      } else if (c == "C") {
        scores[x] = 2;
      } else if (c == "G") {
        scores[x] = 3;
      } else if (c == "T") {
        scores[x] = 4;
      }
    } else {
      c = S.substr(P[x], Q[x] + 1 - P[x]);
      if (c.find('A') != string::npos && c.find('C') != string::npos &&
          c.find('G') != string::npos && c.find('T') != string::npos) {
        scores[x] = 1;
      } else if (c.find('A') != string::npos) {
        scores[x] = 1;
      } else if (c.find('C') != string::npos) {
        scores[x] = 2;
      } else if (c.find('G') != string::npos) {
        scores[x] = 3;
      } else if (c.find('T') != string::npos) {
        scores[x] = 4;
      }
    }
  }
  return scores;
}








//: 0.232

#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores(P.size());
  string c;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c == "A") {
        scores[x] = 1;
      } else if (c == "C") {
        scores[x] = 2;
      } else if (c == "G") {
        scores[x] = 3;
      } else if (c == "T") {
        scores[x] = 4;
      }
    } else {
      c = (S.substr(P[x], Q[x] + 1 - P[x]));
      if (c.size() > 3 && c.find('A') != string::npos &&
          c.find('C') != string::npos && c.find('G') != string::npos &&
          c.find('T') != string::npos) {
        scores[x] = 1;
      } else if (c.find('A') != string::npos) {
        scores[x] = 1;
      } else if (c.find('C') != string::npos) {
        scores[x] = 2;
      } else if (c.find('G') != string::npos) {
        scores[x] = 3;
      } else if (c.find('T') != string::npos) {
        scores[x] = 4;
      }
    }
  }
  return scores;
}














//0.236
#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores(P.size());
  string c;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c.find('A') != string::npos) {
        scores[x]=1;
      } else if (c.find('C') != string::npos) {
        scores[x]=2;
      } else if (c.find('G') != string::npos) {
        scores[x]=3;
      } else if (c.find('T') != string::npos) {
        scores[x]=4;
      }
    } else {
      c = (S.substr(P[x], Q[x] + 1 - P[x]));
      if (c.size() > 3 && c.find('A') != string::npos &&
          c.find('C') != string::npos && c.find('G') != string::npos &&
          c.find('T') != string::npos) {
        scores[x]=1;
      } else if (c.find('A') != string::npos) {
        scores[x]=1;
      } else if (c.find('C') != string::npos) {
        scores[x]=2;
      } else if (c.find('G') != string::npos) {
        scores[x]=3;
      } else if (c.find('T') != string::npos) {
        scores[x]=4;
      }
    }
  }
  return scores;
}







// 0.240 sec

#include <algorithm>
#include <string>
#include <vector>
#include <bits/stdc++.h>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
clock_t start, end;
start = clock();
  vector<int> scores;
  string c;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c == "T") {
      cout << "test";
      }
      if (c=="A") {
        scores.push_back(1);
      } else if (c=="C") {
        scores.push_back(2);
      } else if (c=="G") {
        scores.push_back(3);
      } else if (c=="T") {
        scores.push_back(4);
      }
    } else {
      c = (S.substr(P[x], Q[x] + 1 - P[x]));
      if (c.size() > 3 && c.find('A') != string::npos &&
          c.find('C') != string::npos && c.find('G') != string::npos &&
          c.find('T') != string::npos) {
        scores.push_back(1);
      } else if (c.find('A') != string::npos) {
        scores.push_back(1);
      } else if (c.find('C') != string::npos) {
        scores.push_back(2);
      } else if (c.find('G') != string::npos) {
        scores.push_back(3);
      } else if (c.find('T') != string::npos) {
        scores.push_back(4);
      }
    }
  }
   end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  return scores;
}









// 0.248
#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores;
  string c;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      bool test = if (c == 'T');
      cout << test;
      if (c.find('A') != string::npos) {
        scores.push_back(1);
      } else if (c.find('C') != string::npos) {
        scores.push_back(2);
      } else if (c.find('G') != string::npos) {
        scores.push_back(3);
      } else if (c.find('T') != string::npos) {
        scores.push_back(4);
      }
    } else {
      c = (S.substr(P[x], Q[x] + 1 - P[x]));
      if (c.size() > 3 && c.find('A') != string::npos &&
          c.find('C') != string::npos && c.find('G') != string::npos &&
          c.find('T') != string::npos) {
        scores.push_back(1);
      } else if (c.find('A') != string::npos) {
        scores.push_back(1);
      } else if (c.find('C') != string::npos) {
        scores.push_back(2);
      } else if (c.find('G') != string::npos) {
        scores.push_back(3);
      } else if (c.find('T') != string::npos) {
        scores.push_back(4);
      }
    }
  }
  return scores;
}












//62% too slow

#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<string> vect(P.size());
  vector<int> scores;
  string c;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      vect[x] = c;

    } else {
      vect[x] = (S.substr(P[x], Q[x] + 1 - P[x]));
    }
  }
  for (unsigned int x = 0; x < vect.size(); x += 1) {
    if (vect[x].size() > 3 && vect[x].find('A') != string::npos &&
        vect[x].find('C') != string::npos &&
        vect[x].find('G') != string::npos &&
        vect[x].find('T') != string::npos) {
      scores.push_back(1);
    } else if (vect[x].find('A') != string::npos) {
      scores.push_back(1);
    } else if (vect[x].find('C') != string::npos) {
      scores.push_back(2);
    } else if (vect[x].find('G') != string::npos) {
      scores.push_back(3);
    } else if (vect[x].find('T') != string::npos) {
      scores.push_back(4);
    }
  }
  return scores;
}








//#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
/* clock_t start, end;
start = clock(); */
  vector<string> vect(P.size());
  vector<int> scores;

  for (unsigned int x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      vect[x] = S[P[x]];
    } else {
      vect[x] = (S.substr(P[x], Q[x] + 1 - P[x]));
    }
  }
  for (unsigned int x = 0; x < vect.size(); x += 1) {
    if (vect[x].size() > 3) { 
        if(vect[x].find('A') != string::npos &&
        vect[x].find('C') != string::npos &&
        vect[x].find('G') != string::npos &&
        vect[x].find('T') != string::npos) {
        scores.push_back(1);}
    } else if (vect[x].find('A') != string::npos) {
      scores.push_back(1);
    } else if (vect[x].find('C') != string::npos) {
      scores.push_back(2);
    } else if (vect[x].find('G') != string::npos) {
      scores.push_back(3);
    } else if (vect[x].find('T') != string::npos) {
      scores.push_back(4);
    }
  }
/*  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl; */
  return scores;
}