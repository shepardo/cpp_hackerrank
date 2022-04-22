#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        /*
        std::stringstream ss;
        ss << std::setfill('0') << "0x" << std::hex << ((int)A);
        return ss.str();

        std::stringstream ss2;
        ss2 << std::setfill('-') << std::setw(15) << std::fixed << std::setprecision(2) << (B > 0)? "+" : "-" << (B);
        return ss2.str();

        std::stringstream ss3;
        ss2 << std::setfill('-') << std::setw(15) << std::scientific << std::setprecision(9) << (C);
        return ss2.str();
        */

        std::ios_base::fmtflags f( cout.flags() );
        cout << "0x" << std::hex << ((int)A) << endl;
        cout.flags( f );

        cout << std::setfill('-') << std::setw(15) << std::fixed << std::setprecision(2) << ((B > 0)? "+" : "-" )<< (B) << endl;
        cout.flags( f );

        cout << std::setfill('-') << std::setw(15) << std::scientific << std::setprecision(9) << (C) << endl;
        cout.flags( f );


	}
	return 0;

}