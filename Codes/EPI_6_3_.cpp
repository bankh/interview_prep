template <typename HeightType>
HeightType find_battery_capacity(const vector<HeightType>&h)
{
    HeightType min_height = numeric_limits<HeightType>::max(), capacity = 0;
    for (const HeightType &height : h)
    {
        capacity = max(capacity, height - min_height);
        min_height = min(min_height, height);
    }
    return capacity;
}