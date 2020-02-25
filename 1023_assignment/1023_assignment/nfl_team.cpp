/* NFL TEAMS assignment
los_angeles_rams 7 0.571 1350
create a struct representing the team's name, its wins, losses, ties, and elo, AND a custom container for the teams
-- output by elo (descending), then by name. Calculate team(s) with most wins, and team(s) with most losses*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


struct team {
	string name;
	double rate;
	int wins;
	int losses;
	int ties = 0;
	double elo;

	//team() : team("", 0, 0.0, 0.0) {}
	//team(string name_, int wins_, int losses_, double elo_) :name(name_), wins(wins_), losses(losses_), elo(elo_) {
	//	losses_ = (int)(wins / rate) - wins;
	//}

	friend std::istream& operator >> (std::istream& is, team& tm) {
		return is >> tm.name >> tm.wins >> tm.rate >> tm.elo;
		tm.losses = (int)(tm.wins / tm.rate) - tm.wins;
	}

	friend std::ostream& operator << (std::ostream& cs, const team& tm) {
		return cs << tm.name << " " << tm.wins << " " << tm.losses<< " " << tm.elo << "\n";
	}

	bool operator<(team& tm) const {
		return (elo > tm.elo) || (elo == tm.elo && name < tm.name);
	}

};

class team_list {
public:
	team_list() :teams_() {}

	void add_back(team item) {
		teams_.push_back(item);
	}

	void most_wins() const {
		string most_wins_name = "";
		int most_wins = 0;

		for (const team& tm : teams_) {
			if (most_wins < tm.wins) {
				most_wins = tm.wins;
				most_wins_name = tm.name;
			}
			if (most_wins == tm.wins) {
				cout << tm.name << " & ";
			}
		}
	}

	string most_losses() const {
		string most_losses_name = "";
		int most_losses = 0;

		for (const team& tm : teams_) {
			if (most_losses < tm.losses) {
				most_losses = tm.losses;
				most_losses_name = tm.name;
			}
		}
		return most_losses_name;
	}

	friend ostream& operator<<(ostream& os, team_list& tl) {
		if (tl.teams_.empty()) return os << "No teams\n";

		cout << "\n======== Original =======\n";
		for (const team& tm : tl.teams_)
			os << tm;

		cout << "\n======== After sort =======\n";
		sort(tl.teams_.begin(), tl.teams_.end());
		for (const team& tm : tl.teams_)
			os << tm;

		cout << "\n Most wins : ";
		tl.most_wins();
		return os;
	}

private:
	vector<team> teams_;
};

int main(int argc, const char * argv[]) {

	if (argc != 2) {
		cerr << "Usage: prog filename\n";
		exit(1);
	}

	std::string fname = argv[1];
	std::cout << "Filename is " << fname << ".\n";

	std::ifstream ifs(fname);
	if (!ifs.is_open()) {
		cerr << "We could not open " << fname << ".\n";
		exit(2);
	}

	team tm;
	team_list tl;
	while (ifs >> tm) {
		tl.add_back(tm);
	}
	cout << "\n" << tl;

	ifs.close();

	return 0;
}