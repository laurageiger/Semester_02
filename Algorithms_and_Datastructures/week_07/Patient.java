package ex1;

public class Patient {
    private String name;
    private int id;
    private String severity;
    private int severityGrade;
    private long timeOfAdmission;
    private boolean insuredPrivately;

    public Patient(String name, String severity, long timeOfAdmission, boolean insuredPrivately) { // constructor
        this.name = name;
        this.timeOfAdmission = timeOfAdmission;
        this.insuredPrivately = insuredPrivately;

        switch(severity){ // assign numbers because easier to compare patients
            case "SEVERE":
                this.severityGrade = 3;
                break;
            case "SERIOUS":
                this.severityGrade = 2;
                break;
            case "MODERATE":
                this.severityGrade = 1;
                break;
        }
    }

    // getter and setter

    public boolean isInsuredPrivately() {
        return insuredPrivately;
    }

    public void setInsuredPrivately(boolean insuredPrivately) {
        this.insuredPrivately = insuredPrivately;
    }

    public long getTimeOfAdmission() {
        return timeOfAdmission;
    }

    public void setTimeOfAdmission(long timeOfAdmission) {
        this.timeOfAdmission = timeOfAdmission;
    }

    public int getSeverityGrade() {
        return severityGrade;
    }

    public void setSeverityGrade(int severityGrade) {
        this.severityGrade = severityGrade;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
