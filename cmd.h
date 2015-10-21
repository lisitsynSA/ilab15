///template: CMD_(number of command, description, todo, tmp_value)
CMD_(0, exit, done = 0;,)
CMD_(1, dump, printf("Dump of matrix: ");
                scanf("%d", &arg1);
                if ((arg1 > 0) && (arg1 < 3))
                    MATRIX_DUMP(mat_array[arg1]);, int arg1 = 0)
CMD_(2, set_element, \
            printf("Matrix: ");
            scanf("%d", &arg1);
            if ((arg1 >= 0) && (arg1 < 3))
            {
                printf("X Y: ");
                scanf("%d%d", &arg2, &arg3);
                if ((arg2 >= 0) && (arg2 < size) && (arg3 >= 0) && (arg3 < size))
                {
                    printf("Matrix[%d] (%d, %d) = ", arg1, arg2, arg3);
                    scanf("%lf", &tmp);
                    Matrix_set_element(&mat_array[arg1], arg2, arg3, tmp);
                }
            }, int arg1 = 0; int arg2 = 0; int arg3 = 0;double tmp = 0)
