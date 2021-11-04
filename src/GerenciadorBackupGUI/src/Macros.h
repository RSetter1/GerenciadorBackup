#pragma once

#define COL_ATIVO_IDX      0
#define COL_ATIVO_TAM     60
#define COL_DIRETORIO_IDX  1
#define COL_DIRETORIO_TAM MAX_PATH

// *******************************************************************************
// MACRO PARA INICIALIZAÇÃO DAS LISTAS ORIGEM E DESTINO -> GerenciadorBackupGUIDlg
// *******************************************************************************

// Origem | Destino
#define INICIALIZA_CONTROLES_LISTA(tipo) \
m_list##tipo.InsertColumn  (COL_ATIVO_IDX               , L"Ativo"               ); \
m_list##tipo.SetColumnWidth(COL_ATIVO_IDX               , COL_ATIVO_TAM          ); \
m_list##tipo.InsertColumn  (COL_DIRETORIO_IDX           , L"Diretório"           ); \
m_list##tipo.SetColumnWidth(COL_DIRETORIO_IDX           , COL_DIRETORIO_TAM      ); \
m_list##tipo.SendMessage   (LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT); \
                                                                                    \
m_edtDiretorio##tipo   .SetCueBanner(L"Informe o Diretório de " #tipo);             \
m_btnSearchFolder##tipo.SetIcon     (m_hIconSearchFolder);                          \
m_btnAdd##tipo         .SetIcon     (m_hIconAdd         );                          \
m_btnChange##tipo      .SetIcon     (m_hIconEdit        );                          \
m_btnRemove##tipo      .SetIcon     (m_hIconRemove      );

// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
