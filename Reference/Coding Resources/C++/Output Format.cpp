// 18
int main() {
  ios state(nullptr);
  state.copyfmt(cout);  // saves current format state
  double D = 13.34567;
  cout << setprecision(4) << D << endl  // 13.35
       << fixed << D << endl;           // 13.3457
  cout.copyfmt(state);  // restores format
  int N = 13;
  cout << setw(4) << N << endl       // "  13"
       << setfill('0') << N << endl  // "0013"
       << left << N << endl          // "1300"
       << right << N << endl         // "0013"
       << hex << N << endl           // "000d"
       << uppercase << N << endl     // "000D"
       << nouppercase << N << endl   // "000d"
       << oct << N << endl           // "0015"
       << dec << N << endl;          // "0013"
}