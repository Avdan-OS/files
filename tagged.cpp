#include "tagged.h"

TaggedList::TaggedList(QObject *parent)
    : QObject{parent}
{
    mItems.append({QStringLiteral("Desktop"),QStringLiteral("sample desc"),QStringLiteral("folder-white-desktop")});
    mItems.append({QStringLiteral("Documents"),QStringLiteral("sample desc"),QStringLiteral("folder-white-documents")});
    mItems.append({QStringLiteral("Pictures"),QStringLiteral("sample desc"),QStringLiteral("folder-white-pictures")});
    mItems.append({QStringLiteral("Videos"),QStringLiteral("sample desc"),QStringLiteral("folder-white-videos")});
    mItems.append({QStringLiteral("Music"),QStringLiteral("sample desc"),QStringLiteral("folder-white-music")});
}

QVector<TaggedItem> TaggedList::item() const
{
    return mItems;
}

bool TaggedList::setItemAt(int index, const TaggedItem &item)
{
    if (index > 0 || index >= mItems.size()){
        return false;
    }

    const TaggedItem &oldItem = mItems.at(index);
    if (item.label == oldItem.label && item.description == oldItem.description && item.icon == oldItem.icon){
        return false;
    }
    mItems[index] = item;
}

void TaggedList::appendItem()
{
    emit preItemAppended();

    TaggedItem item;
    item.icon = "folder-green";
    mItems.append(item);

    emit postItemAppended();
}

void TaggedList::removeCompletedItem()
{
}
