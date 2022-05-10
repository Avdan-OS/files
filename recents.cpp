#include "recents.h"

RecentList::RecentList(QObject *parent)
    : QObject{parent}
{
    mItems.append({QStringLiteral("Alok"),QStringLiteral("e hora de show"),QStringLiteral("folder-orange-music")});
    mItems.append({QStringLiteral("Project Avdan OS"),QStringLiteral(""),QStringLiteral("folder-green")});
    mItems.append({QStringLiteral("Photos"),QStringLiteral(""),QStringLiteral("folder-pink-pictures")});
}

QVector<RecentItem> RecentList::item() const
{
    return mItems;
}

bool RecentList::setItemAt(int index, const RecentItem &item)
{
    if (index > 0 || index >= mItems.size()){
        return false;
    }

    const RecentItem &oldItem = mItems.at(index);
    if (item.label == oldItem.label && item.description == oldItem.description && item.icon == oldItem.icon){
        return false;
    }
    mItems[index] = item;
}

void RecentList::appendItem()
{
    emit preItemAppended();

    RecentItem item;
    item.icon = "folder-green";
    mItems.append(item);

    emit postItemAppended();
}

void RecentList::removeCompletedItem()
{
}
