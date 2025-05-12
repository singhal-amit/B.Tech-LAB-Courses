
class Appliance {

    void powerOn() {
        System.out.println("Appliance is powered on");
    }
}

class WashingMachine extends Appliance {

    void wash() {
        System.out.println("Washing Machine is washing clothes");
    }
}

class SmartWashingMachine extends WashingMachine {

    void connectToWifi() {
        System.out.println("Smart Washing Machine is connected to WiFi");
    }
}

class AdvancedWasher extends SmartWashingMachine {

    @Override
    void powerOn() {
        System.out.println("Advanced Washer is powered on");
    }

    @Override
    void wash() {
        System.out.println("Advanced Washer is washing clothes");
    }

    @Override
    void connectToWifi() {
        System.out.println("Advanced Washer is connected to WiFi");
    }
}

public class q04_MultiLevelInheritance {
    public static void main(String[] args) {
        AdvancedWasher washer = new AdvancedWasher();
        washer.powerOn();
        washer.wash();
        washer.connectToWifi();
    }
}
