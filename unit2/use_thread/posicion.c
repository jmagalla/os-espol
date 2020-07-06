/* structure for passing data to threads */
typedef struct
{
    int row;
    int column;
} parameters;

void main()
{
    parameters *data = (parameters *) malloc(sizeof(parameters));
    data->row = 1;
    data->column = 1;
}