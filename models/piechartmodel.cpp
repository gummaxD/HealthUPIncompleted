#include "piechartmodel.h"

PieChartModel::PieChartModel(CalendarModel* am)
{
    infoGiorno["Carboidrati"] = am->getCurrentGiorno()->CarboidratiTotali();
    infoGiorno["Grassi"] = am->getCurrentGiorno()->CarboidratiTotali();
    infoGiorno["Proteine"]= am->getCurrentGiorno()->ProteineTotali();
}

QMap<QString,unsigned int> PieChartModel::getInfoGiorno() const{
    return infoGiorno;
}
