package com.shik;

import java.util.Random;

public class GetRandomNumbers {
    static int times_called = 0, chance_of_end = 1;
    static Random random;

    public GetRandomNumbers() {
        random = new Random();
    }

    public static int getRandomNumber() {
        if (times_called > 50000) {
            chance_of_end = 10;
        }
        else if (times_called > 40000) {
            chance_of_end = 5;
        }
        else if (times_called > 30000) {
            chance_of_end = 7;
        }
        else if (times_called > 20000) {
            chance_of_end = 6;
        }
        else if (times_called > 10000) {
            chance_of_end = 5;
        }
        else if (times_called > 5000) {
            chance_of_end = 3;
        }
        else if (times_called > 2500) {
            chance_of_end = 4;
        }
        else if (times_called > 1200) {
            chance_of_end = 2;
        }
        else if (times_called > 1000) {
            chance_of_end = 7;
        }
        else if (times_called > 500) {
            chance_of_end = 5;
        }
        else if (times_called > 200) {
            chance_of_end = 3;
        }
        times_called++;
        int chance = random.nextInt(10) + 1;
        int num;
        if (chance <= chance_of_end) {
            num = -1;
        } else {
            num = random.nextInt(50);
        }
        return num;
    }
}
