double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double ans = 0.0;
    int combined = nums1Size + nums2Size, p1 = 0, p2 = 0, i = 0;
    int halfway = ceil(combined / 2.0);

    if (combined % 2 == 0) // Even arrays will have two median elements
        halfway++;

    int halfwayArray[halfway];

    for (; i < halfway; i++) {
        if (p1 < nums1Size && p2 < nums2Size && nums1[p1] < nums2[p2])
            halfwayArray[i] = nums1[p1++];
        else if (p2 < nums2Size)
            halfwayArray[i] = nums2[p2++];
        
        else {
            if (p1 < nums1Size) 
                halfwayArray[i] = nums1[p1++];
            else if (p2 < nums2Size) 
                halfwayArray[i] = nums2[p2++];
        }
    }

    ans = halfwayArray[i - 1];
    if (combined % 2 == 0)
        ans = (ans + halfwayArray[i - 2]) / 2;

    return ans;
}
