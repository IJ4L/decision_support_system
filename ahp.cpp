#include <iostream>
#include <list>
#include <conio.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    
    list<pair<double, int>> pair_listPerengkingan;

    int jumlahKriteria, jumlahAlternatif, skip = 0;
    double kriteria[10][10], totalKriteria[10], alternatif[10][10][10], totalAlternatif[10][10];
    double normalisasiKriteria[10][10], totalnk[10], ci[10];
    double totalcm, lamdaMax, ci2, ri, cr, tbp[10][10], perengkingan[10];
    double rasioIndeks[14] = {0, 0, 0.58, 0.9, 1.12, 1.24, 1.32, 1.41, 1.45, 1.49, 1.51, 1.48, 1.56, 1.59};

    cout << "MASUKKAN JUMLAH KRITERIA      : ";
    cin >> jumlahKriteria;

    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {

            if (i == k)
            {
                kriteria[k][i] = 1;
            }
            else if (i < 1)
            {
                cout << "MASUKKAN NILAI KRITERIA C" << k + 1 << " C" << i + 1 << " : ";
                cin >> kriteria[k][i];
            }
            else
            {
                if (k <= skip)
                {
                    kriteria[k][i] = 1 / kriteria[skip][k];
                }
                else
                {
                    cout << "MASUKKAN NILAI KRITERIA C" << k + 1 << " C" << i + 1 << " : ";
                    cin >> kriteria[k][i];
                }
            }
        }
        skip++;
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {
            totalKriteria[i] = totalKriteria[i] + kriteria[k][i];
        }
    }

    cout << endl;
    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {
            cout << "\t" << fixed << setprecision(3) << kriteria[i][k] << fixed << setprecision(0) << "\t";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------" << endl;
    for (int l = 0; l < jumlahKriteria; l++)
    {
        cout << "\t" << fixed << setprecision(3) << totalKriteria[l] << fixed << setprecision(0) << "\t";
    }

    cout << endl;

    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {
            normalisasiKriteria[k][i] = kriteria[k][i];
        }
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {

        totalnk[i] = totalKriteria[i];
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {
            normalisasiKriteria[k][i] = normalisasiKriteria[k][i] / totalnk[i];
        }
    }

    cout << endl
         << "NORMALISASI KRITERIA" << endl;
    for (int i = 0; i < jumlahKriteria; i++)
    {

        for (int k = 0; k < jumlahKriteria; k++)
        {
            cout << "\t" << fixed << setprecision(3) << normalisasiKriteria[i][k] << fixed << setprecision(0) << " \t";
        }
        cout << endl;
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {
        totalnk[i] = 0;
        for (int k = 0; k < jumlahKriteria; k++)
        {
            totalnk[i] = totalnk[i] + normalisasiKriteria[i][k];
        }
        totalnk[i] = totalnk[i] / 6;
    }

    cout << "--------------------------------------------------" << endl;
    for (int l = 0; l < jumlahKriteria; l++)
    {
        cout << "\t" << fixed << setprecision(3) << totalnk[l] << fixed << setprecision(0) << "\t";
    }

    cout << endl
         << endl;

    cout << "MASUKKAN JUMLAH ALTERNAITF : ";
    cin >> jumlahAlternatif;
    for (int s = 0; s < jumlahKriteria; s++)
    {
        skip = 0;
        for (int i = 0; i < jumlahAlternatif; i++)
        {
            for (int k = 0; k < jumlahAlternatif; k++)
            {

                if (i == k)
                {
                    alternatif[s][k][i] = 1;
                }
                else if (i < 1)
                {
                    cout << "MASUKKAN NILAI ALTERNATIF A" << k + 1 << " A" << i + 1 << " : ";
                    cin >> alternatif[s][k][i];
                }
                else
                {
                    if (k <= skip)
                    {
                        alternatif[s][k][i] = 1 / alternatif[s][skip][k];
                    }
                    else
                    {
                        cout << "MASUKKAN NILAI ALTERNATIF A" << k + 1 << " A" << i + 1 << " : ";
                        cin >> alternatif[s][k][i];
                    }
                }
            }
            skip++;
        }
    }

    for (int s = 0; s < jumlahKriteria; s++)
    {
        for (int i = 0; i < jumlahAlternatif; i++)
        {
            for (int k = 0; k < jumlahAlternatif; k++)
            {
                totalAlternatif[s][i] = totalAlternatif[s][i] + alternatif[s][k][i];
            }
        }
    }

    cout << endl;
    for (int s = 0; s < jumlahKriteria; s++)
    {
        cout << endl;

        cout << "==============" << endl;
        cout << "KRITERIA " << s + 1 << endl;
        cout << "==============" << endl;
        for (int i = 0; i < jumlahAlternatif; i++)
        {
            for (int k = 0; k < jumlahAlternatif; k++)
            {
                cout << "\t" << fixed << setprecision(3) << alternatif[s][i][k] << fixed << setprecision(0) << "\t";
            }
            cout << fixed << setprecision(3) << totalAlternatif[s][i] << fixed << setprecision(0) << "\t";
            cout << endl;
        }
    }

    for (int s = 0; s < jumlahKriteria; s++)
    {
        for (int i = 0; i < jumlahAlternatif; i++)
        {
            for (int k = 0; k < jumlahAlternatif; k++)
            {
                alternatif[s][k][i] = alternatif[s][k][i] / totalAlternatif[s][i];
            }
        }

        for (int i = 0; i < jumlahAlternatif; i++)
        {
            totalAlternatif[s][i] = 0;
            for (int k = 0; k < jumlahAlternatif; k++)
            {
                totalAlternatif[s][i] = totalAlternatif[s][i] + alternatif[s][i][k];
            }
            totalAlternatif[s][i] = totalAlternatif[s][i] / jumlahAlternatif;
            tbp[i][0] = totalAlternatif[s][i];
        }
        cout << "============================" << endl;
        cout << "NORMALISASI ALTERNATIF" << endl;
        cout << "============================" << endl;
        for (int i = 0; i < jumlahAlternatif; i++)
        {

            for (int k = 0; k < jumlahAlternatif; k++)
            {
                cout << "\t" << fixed << setprecision(3) << alternatif[s][i][k] << fixed << setprecision(0) << " \t";
            }
            cout << fixed << setprecision(3) << totalAlternatif[s][i] << fixed << setprecision(0) << "\t";
            cout << endl;
        }
    }

    cout << endl;

    totalcm = 0;
    for (int i = 0; i < jumlahKriteria; i++)
    {
        ci[i] = (kriteria[i][0] * totalnk[0]) + (kriteria[i][1] * totalnk[1]) + (kriteria[i][2] * totalnk[2]) + (kriteria[i][3] * totalnk[3]) + (kriteria[i][4] * totalnk[4]) + (kriteria[i][5] * totalnk[5]) / totalnk[i];

        totalcm = ci[i] + totalcm;
    }

    cout << "=======================================" << endl;
    cout << "CM" << endl;
    for (int i = 0; i < jumlahKriteria; i++)
    {
        cout << "\t" << fixed << setprecision(3) << ci[i] << fixed << setprecision(0) << "\t";
    }
    cout << endl << "=======================================" << endl;

    lamdaMax = totalcm / jumlahKriteria;
    ci2 = lamdaMax - jumlahKriteria / jumlahKriteria - 1;
    ri = rasioIndeks[jumlahKriteria - 1];
    cr = ci2 / ri;

    cout << endl;
    cout << jumlahKriteria << endl;

    cout << "==============================" << endl;
    cout << "LAMDA MAX   :" << fixed << setprecision(3) << lamdaMax << fixed << setprecision(0) << endl;
    cout << "CI          :" << fixed << setprecision(3) << ci2 << fixed << setprecision(0) << endl;
    cout << "RI          :" << fixed << setprecision(3) << ri << fixed << setprecision(0) << endl;
    cout << "CR          :" << fixed << setprecision(3) << cr << fixed << setprecision(0) << endl;
    cout << "==============================" << endl;

    for (int i = 0; i < jumlahAlternatif; i++)
    {
        perengkingan[i] = (totalnk[0] * totalAlternatif[0][i]) + (totalnk[1] * totalAlternatif[1][i]) + (totalnk[2] * totalAlternatif[2][i]) + (totalnk[3] * totalAlternatif[3][i]) + (totalnk[4] * totalAlternatif[4][i]) + (totalnk[5] * totalAlternatif[5][i]);
    }

     for (int i = 0; i < jumlahAlternatif; i++)
    {
        pair_listPerengkingan.push_front(make_pair(perengkingan[i], i + 1));
    }

    int j = jumlahAlternatif;
    cout << "+---------------------------------------------------------+" << endl;
    cout << "|                     RANKING RESULT                      |" << endl;
    cout << "+---------------------------------------------------------+" << endl;
    pair_listPerengkingan.sort();
    for (auto itr = pair_listPerengkingan.begin(); itr != pair_listPerengkingan.end(); itr++)
    {
        cout << "\t" << fixed << setprecision(4) << itr->first << "\t" << fixed << setprecision(0) << "\tA" << itr->second << "\t" << j << endl;
        j--;
    }
    cout << "+---------------------------------------------------------+" << endl;
}