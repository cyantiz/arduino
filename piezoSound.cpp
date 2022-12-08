void piezoSound()
{
    int toneVal;
    float sinVal;
    for (int i = 0; i < 180; i++)
    {
        sinVal = sin(i * 3.1412 / 180);
        toneVal = int(sinVal * 1000) + 2000;
        tone(8, toneVal);
    }
}