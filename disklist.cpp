#include "disklist.h"

DiskList::DiskList(QObject *parent)
    : QObject{parent}
{
    mItems.append({QStringLiteral("Alok & Bhaskar"),QStringLiteral("e hora de show"),QStringLiteral("drive-harddisk-symbolic")});
    mItems.append({QStringLiteral("My dream SSD"),QStringLiteral("Your Dream can't be true"),QStringLiteral("drive-harddisk-solidstate-symbolic")});
    mItems.append({QStringLiteral("Area 51"),QStringLiteral("Area 51 Leaked Pictures"),QStringLiteral("drive-harddisk-solidstate-symbolic")});
    mItems.append({QStringLiteral("Avdan OS"),QStringLiteral("System Drive"),QStringLiteral("drive-harddisk-system-symbolic")});
}

QVector<DiskItem> DiskList::item() const
{
    return mItems;
}

bool DiskList::setItemAt(int index, const DiskItem &item)
{
    if (index > 0 || index >= mItems.size()){
        return false;
    }

    const DiskItem &oldItem = mItems.at(index);
    if (item.label == oldItem.label && item.description == oldItem.description && item.icon == oldItem.icon){
        return false;
    }
    mItems[index] = item;
}

void DiskList::appendItem()
{
    emit preItemAppended();

    DiskItem item;
    item.icon = "folder-green";
    mItems.append(item);

    emit postItemAppended();
}

void DiskList::removeCompletedItem()
{
}
