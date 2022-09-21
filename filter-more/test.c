for (int i = 0 ; i <= 2 ; i ++)
            {
                for (int j = 0 ; j <=2 ; j ++)
                {
                    gxr += (Mx[i][j])*(R[i][j]);
                    gxg += (Mx[i][j])*(G[i][j]);
                    gxb += (Mx[i][j])*(B[i][j]);
                    gyr += (My[i][j])*(R[i][j]);
                    gyg += (My[i][j])*(G[i][j]);
                    gyb += (My[i][j])*(B[i][j]);
                }
            }