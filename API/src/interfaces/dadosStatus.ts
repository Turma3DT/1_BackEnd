export interface StatusRequest {
    status: boolean;
    velocidade: string;
    perdido: boolean;
}

export interface Status {
    status: 'ativo' | 'inativo';
    velocidade: string;
    perdido: 'em rota' | 'perdido';
    dataRegistro: Date;
}
