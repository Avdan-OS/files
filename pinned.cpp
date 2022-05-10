#include "pinned.h"

PinnedList::PinnedList(QObject *parent)
    : QObject{parent}
{
    mItems.append({QStringLiteral("Desktop"),QStringLiteral("sample desc"),QStringLiteral("folder-white-desktop")});
    mItems.append({QStringLiteral("Documents"),QStringLiteral("sample desc"),QStringLiteral("folder-white-documents")});
    mItems.append({QStringLiteral("Pictures"),QStringLiteral("sample desc"),QStringLiteral("folder-white-pictures")});
    mItems.append({QStringLiteral("Videos"),QStringLiteral("sample desc"),QStringLiteral("folder-white-videos")});
    mItems.append({QStringLiteral("Music"),QStringLiteral("sample desc"),QStringLiteral("folder-white-music")});
}

QVector<PinnedItem> PinnedList::item() const
{
    return mItems;
}

bool PinnedList::setItemAt(int index, const PinnedItem &item)
{
    if (index > 0 || index >= mItems.size()){
        return false;
    }

    const PinnedItem &oldItem = mItems.at(index);
    if (item.label == oldItem.label && item.description == oldItem.description && item.icon == oldItem.icon){
        return false;
    }
    mItems[index] = item;
}

void PinnedList::appendItem()
{
    emit preItemAppended();

    PinnedItem item;
    item.icon = "folder-green";
    mItems.append(item);

    emit postItemAppended();
}

void PinnedList::removeCompletedItem()
{
}
