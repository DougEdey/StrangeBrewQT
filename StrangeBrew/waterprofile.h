#ifndef WATERPROFILE_H
#define WATERPROFILE_H

#include <QString>
#include <vector>

#include <sbstringutils.h>

class WaterProfile
{
private:
    QString name;
    QString description;
    double ca;
    double mg;
    double na;
    double so4;
    double hco3;
    double cl;
    double hardness;
    double tds;
    double ph;
    double alkalinity;
    static std::vector<WaterProfile> profiles;

public:
    WaterProfile();
    WaterProfile(QString name);
    double getAlkalinity();
    double getCa();
    double getCl();
    QString getDescription();
    double getHardness();
    double getHco3();
    double getMg();
    double getNa();
    QString getName();
    double getPh();
    double getSo4();
    double getTds();
    void setAlkalinity(double alkalinity);
    void setCa(double ca);
    void setCl(double cl);
    void setDescription(QString description);
    void setHardness(double hardness);
    void setHco3(double hco3);
    void setMg(double mg);
    void setNa(double na);
    void setName(QString name);
    void setPh(double ph);
    void setSo4(double so4);
    void setTds(double tds);
    QString toString();
    QString toXML(int indent);
    int compareTo(WaterProfile w);
    static void setProfiles(std::vector<WaterProfile>);
    bool operator ==(const WaterProfile &other) const;
    bool operator <(const WaterProfile &second) const;
};

#endif // WATERPROFILE_H
