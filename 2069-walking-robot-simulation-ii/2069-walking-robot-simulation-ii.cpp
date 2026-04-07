class Robot {
public:
    int x, y;
    int w, h;
    string d;
    int per; // perimeter

    Robot(int width, int height) {
        x = 0;
        y = 0;
        d = "East";
        w = width;
        h = height;

        per = 2 * (w - 1) + 2 * (h - 1);
    }

    void step(int num) {
        num %= per;
        if (num == 0) num = per;

        while (num > 0) {

            if (d == "East") {
                int mv = min(num, (w - 1) - x);
                x += mv;
                num -= mv;
                if (num > 0) d = "North";
            }

            else if (d == "North") {
                int mv = min(num, (h - 1) - y);
                y += mv;
                num -= mv;
                if (num > 0) d = "West";
            }

            else if (d == "West") {
                int mv = min(num, x);
                x -= mv;
                num -= mv;
                if (num > 0) d = "South";
            }

            else { // South
                int mv = min(num, y);
                y -= mv;
                num -= mv;
                if (num > 0) d = "East";
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return d;
    }
};